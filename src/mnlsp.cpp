#include"mnlsp.hpp"


namespace mnlsp
{
    // ---BEGIN--- From: https://stackoverflow.com/a/26221725
    template<typename ... Args>
    std::string strf(const std::string& format, Args ... args)
    {
        int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
        if( size_s <= 0 ){throw std::runtime_error("Error during formatting.");}
        auto size = static_cast<size_t>(size_s);
        auto buf = std::make_unique<char[]>(size);
        std::snprintf(buf.get(), size, format.c_str(), args ...);
        return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
    }
    // ---END--- From: https://stackoverflow.com/a/26221725

    std::string dtype_str(DataType dtype)
    {
        switch(dtype)
        {
            case DataType::UNKNOWN:  return std::string("UNKNOWN");
            case DataType::NUMBER:   return std::string("NUMBER");
            case DataType::BOOLEAN:  return std::string("BOOLEAN");
            case DataType::FUNCTION: return std::string("FUNCTION");
        }
    }

    RTES* mnlsp_init()
    {
        // TODO: Other init?
        RTE* rte = RTE::get_base_rte();
        RTES* rtes = new RTES();
        rtes->enter_env(rte);
        // TODO: No new_bif in runtime

        return rtes;
    }

    RTE* RTE::get_base_rte()
    {
        // TODO: Inject builtin functions (only for root)
        RTEOtions rteo;  // Initial value

        RTE* rte = new RTE(rteo);
        RTE* trte;
        trte = rte->new_bif("_", rteo, bif::_);
        trte = rte->new_bif("_plus", rteo, bif::_plus);

        VarNode* n = new VarNode();
        n->vid = "_";
        rte->set_fun((ExpNode*)n);

        return rte;
    }

    RTE::RTE(RTEOtions rteo)
    {
        this->rteo = rteo;
        init();
    }

    void RTE::new_var(const std::string id, const Data data)
    {
        if(vpool.count(id))
            throw (ErrPkt){ErrType::REDEFINE, ERRMSG_REDEFINE(id)};
        vpool[id] = new Data(data);

        return;
    }

    bool RTE::has_var(const std::string id)
    {
        return vpool.find(id) == vpool.end();
    }
    
    Data RTE::get_var(const std::string id)
    {
        auto it = vpool.find(id);
        if(it == vpool.end())
            throw (ErrPkt){ErrType::VAR_NOT_FOUND, ERRMSG_VAR_NOT_FOUND(id)};

        return *((*it).second);
    }

    void RTE::set_var(const std::string id, const Data data)
    {
        if(!has_var(id)) *(vpool[id]) = data;
        else throw (ErrPkt){ErrType::VAR_NOT_FOUND, ERRMSG_VAR_NOT_FOUND(id)};

        return;
    }

    void RTE::set_fun(ExpNode* fun)
    {
        this->fun = fun;

        return;
    }

    void RTE::add_param(const std::string id)
    {
        // TODO: Inject params
        // TODO: Inject eval variable
        // TODO: Inject options
        // TODO:
        // Bind to parameters literal name and do the body
        // Params cross RTE

        ppool.push_back(id);
        new_var(id, Data());
        set_var("_p", Data((int)ppool.size()));

        return;
    }

    void RTE::add_params(std::vector<std::string> ids)
    {
        for(std::string id : ids)
        {
            ppool.push_back(id);
            new_var(id, Data());
        }
        new_var("_p", Data((int)ppool.size()));

        return;
    }

    std::vector<Data> RTE::get_all_params()
    {
        std::vector<Data> datas;
        for(std::string id : ppool) datas.push_back(get_var(id));

        return datas;
    }

    Data RTE::eval(RTES* rtes)
    {
        rtes->enter_env(this);
        Data data;
        if(bif != nullptr) data = bif(rtes);
        else               data = eval_node(rtes, fun);
        set_var("_v", data);
        rtes->leave_env();

        return data;
    }

    void RTE::param_eval(RTES* rtes, signed int pn)
    {
        rtes->enter_env(this);
        int pnum = ppool.size();
        std::string pid;
        ExpNode* p;
        if(pn >= 0)
        {
            pid = ppool[pn % pnum];
            p = params[pn % pnum];
        }
        else
        {
            pid = ppool.end()[((pn + 1) % pnum) - 1];
            p = params.end()[((pn + 1) % pnum) - 1];
        }
        set_var(pid,
                p->ntype == NodeType::LIT
                ? ((LitNode*)p)->data
                : eval_node(rtes, p));
        rtes->leave_env();

        return;
    }

    void RTE::params_eval(RTES* rtes)
    {
        for(int i = 0; i < ppool.size(); i++) param_eval(rtes, i);

        return;
    }

    Data RTE::eval_data(RTES* rtes, Data data)
    {
        switch(data.dtype)
        {
            case DataType::NUMBER:
            case DataType::BOOLEAN:
                return data;

            case DataType::FUNCTION:
            {
                RTE* rte = new RTE(*data.d.fval);
                rte->init();
                return rte->eval(rtes);
            }

            case DataType::UNKNOWN:
            default:
                // TODO: Error handle (when use it)
                return data;
        }
    }

    Data RTE::eval_var(RTES* rtes, const std::string id)
    {
        return eval_data(rtes, rtes->get_var(id));
    }

    Data RTE::eval_node(RTES* rtes, ExpNode* node)
    {
        if(node->ntype == NodeType::LIT)
             return eval_data(rtes, ((LitNode*)node)->data);
        else return eval_var(rtes, ((VarNode*)node)->vid);
    }

    void RTE::init()
    {
        bif = nullptr;
        vpool.clear();

        new_var("_v", Data());
        new_var("_p", Data(0));

        return;
    }

    RTE* RTE::new_bif(const std::string id, RTEOtions rteo, Data (*bif)(RTES* rtes))
    {
        RTE* rte = new RTE(rteo);
        rte->bif = bif;
        new_var(id, Data(rte));

        return rte;
    }

    RTES::RTES()
    {
        init();
    }

    void RTES::new_var(const std::string id, const Data data)
    {
        rtev.back()->new_var(id, data);

        return;
    }

    bool RTES::has_var(const std::string id)
    {
        for(auto it = rtev.rbegin(); it != rtev.rend(); it++)
            if((*it)->has_var(id)) return true;

        return false;
    }

    Data RTES::get_var(const std::string id)
    {
        for(auto it = rtev.rbegin(); it != rtev.rend(); it++)
            if((*it)->has_var(id)) return (*it)->get_var(id);

        throw (ErrPkt){ErrType::VAR_NOT_FOUND_G, ERRMSG_VAR_NOT_FOUND_G(id)};
    }

    void RTES::set_var(const std::string id, const Data data)
    {
        for(auto it = rtev.rbegin(); it != rtev.rend(); it++)
            if((*it)->has_var(id)){(*it)->set_var(id, data); return;}

        throw (ErrPkt){ErrType::VAR_NOT_FOUND_G, ERRMSG_VAR_NOT_FOUND_G(id)};
    }

    void RTES::enter_env(RTE* rte)
    {
        rtev.push_back(rte);

        return;
    }

    void RTES::leave_env()
    {
        if(rtev.size() == 0)
            throw (ErrPkt){ErrType::VAR_NOT_FOUND_G, ERRMSG_NO_MORE_RTE};
        rtev.pop_back();

        return;
    }

    RTE* RTES::get_rte(unsigned int from_back)
    {
        if(rtev.size() == 0)
            throw (ErrPkt){ErrType::VAR_NOT_FOUND_G, ERRMSG_NO_MORE_RTE};

        return rtev.end()[((-from_back + 1) % rtev.size()) - 1];
    }

    void RTES::init()
    {
        rtev.clear();

        return;
    }

    Data bif::_(RTES* rtes)
    {
        rtes->get_rte(1)->params_eval(rtes);

        return Data();
    }

    Data bif::_plus(RTES* rtes)
    {
        // Params: _p-0, _p-1, ...
        // var("_v").set(var("_p-0").get() + get_var("_p-1").get())

        RTE* crte = rtes->get_rte(1);
        crte->params_eval(rtes);

        std::vector<Data> datas = crte->get_all_params();

        int n = 0;
        for(Data d : datas)
        {
            if(d.dtype != DataType::NUMBER)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::NUMBER, d.dtype)};
            n += d.d.ival;
        }

        return Data(n);
    }
}
