#include"mnlsp.hpp"


namespace mnlsp
{
    int test()  // TODO
    {
        std::vector<ExpNode*> n;
        std::vector<std::string> s({"1", "2"});
        n.insert(n.begin(), nullptr);
        // n.push_back();
        sizeof(LitNode);
        sizeof(VarNode);
        sizeof(ExpNode);

        return 0;
    }

    RTES* mnlsp_init()
    {
        // TODO: Other init?
        RTES* rtes = new RTES();
        // TODO: No new_bif in runtime

        return rtes;
    }

    RTE* RTE::get_base_rte()
    {
        // TODO: Inject builtin functions (only for root)
        RTEOtions rteo;  // Initial value

        RTE* rte = new RTE(rteo);
        RTE* trte;
        trte = rte->new_bif("_",           rteo, bif::_);
        trte = rte->new_bif("_print-num",  rteo, bif::_print_num);
        trte = rte->new_bif("_print-bool", rteo, bif::_print_bool);
        trte = rte->new_bif("_plus",       rteo, bif::_plus);
        trte = rte->new_bif("_minus",      rteo, bif::_minus);
        trte = rte->new_bif("_multiply",   rteo, bif::_multiply);
        trte = rte->new_bif("_divide",     rteo, bif::_divide);
        trte = rte->new_bif("_modulus",    rteo, bif::_modulus);
        trte = rte->new_bif("_greater",    rteo, bif::_greater);
        trte = rte->new_bif("_smaller",    rteo, bif::_smaller);
        trte = rte->new_bif("_equal",      rteo, bif::_equal);
        trte = rte->new_bif("_and",        rteo, bif::_and);
        trte = rte->new_bif("_or",         rteo, bif::_or);
        trte = rte->new_bif("_not",        rteo, bif::_not);
        trte = rte->new_bif("_define",     rteo, bif::_define);
        trte = rte->new_bif("_fun",        rteo, bif::_fun);
        trte = rte->new_bif("_fun_call",   rteo, bif::_fun_call);
        trte = rte->new_bif("_if",         rteo, bif::_if);

        VarNode* n = new VarNode();
        n->vid = "_";
        rte->set_fun((ExpNode*)n);

        return rte;
    }

    RTE* RTE::get_var_fun_rte(const std::string id, std::vector<ExpNode*> params)
    {
        RTE* rte = new RTE();
        VarNode* n = new VarNode();
        n->vid = id;
        rte->set_fun((ExpNode*)n);
        rte->add_params(params);

        return rte;
    }

    RTE* RTE::get_lit_fun_rte(RTE* frte,
                              const std::vector<std::string> pids,
                              std::vector<ExpNode*> params)
    {
        RTE* rte = new RTE();
        rte->set_fun(params[0]);
        // rte->get_ppool().assign(pids.begin(), pids.end());
        rte->set_ppool(pids);
        // printf(">>>%d\n", rte->get_ppool().size());
        // for(std::string id : pids) frte->new_var(id, Data());

        return rte;
    }

    Data RTE::eval_rte(RTES* rtes, RTE* rte)
    {
        rtes->enter_env(rte);
        RTE* frte = new RTE(*rte);
        frte->init();
        Data data = frte->eval(rtes);
        rtes->leave_env();

        return data;
    }

    RTE::RTE()
    {
        this->rteo = RTEOtions();
        bif = nullptr;
        init();
    }

    RTE::RTE(RTEOtions rteo)
    {
        this->rteo = rteo;
        bif = nullptr;
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
        return vpool.find(id) != vpool.end();
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
        if(has_var(id)) *(vpool[id]) = data;
        else throw (ErrPkt){ErrType::VAR_NOT_FOUND, ERRMSG_VAR_NOT_FOUND(id)};

        return;
    }

    void RTE::set_fun(ExpNode* fun)
    {
        this->fun = fun;

        return;
    }

    void RTE::add_params(std::vector<std::string> ids, std::vector<ExpNode*> params)
    {
        // TODO: Inject params
        // TODO: Inject eval variable
        // TODO: Inject options
        // TODO:
        // Bind to parameters literal name and do the body
        // Params cross RTE

        for(std::string id : ids)
        {
            ppool.push_back(id);
            new_var(id, Data());
        }
        set_var("_p", Data((int)ppool.size()));
        this->params.insert(this->params.end(), params.begin(), params.end());

        return;
    }

    void RTE::add_params(std::vector<ExpNode*> params)
    {
        std::vector<std::string> ids;
        for(int i = 0; i < params.size(); i++)
            ids.push_back(std::string("_p-") + std::to_string(i));
        add_params(ids, params);

        return;
    }

    std::vector<Data> RTE::get_all_params()
    {
        std::vector<Data> datas;
        for(std::string id : ppool) datas.push_back(get_var(id));

        return datas;
    }
    
    std::vector<std::string> RTE::get_ppool()
    {
        return ppool;
    }

    void RTE::set_ppool(std::vector<std::string> p)
    {
        this->ppool = p;
    }

    std::vector<ExpNode*> RTE::get_params()
    {
        return params;
    }

    Data RTE::eval(RTES* rtes)
    {
        Data data;
        if(bif != nullptr)
        {
            rtes->leave_env();
            data = bif(rtes);
            rtes->enter_env(this);
        }
        else
        {
            // rtes->leave_env();
            // params_eval(rtes);
            data = eval_node(rtes, fun);
            // rtes->enter_env(this);
        }
        set_var("_v", data);

        return data;
    }

    void RTE::params_match(std::vector<Data> datas)
    {
        // printf("  >> pm\n");
        if(ppool.size() != datas.size())
            throw (ErrPkt){ErrType::WRONG_PARAM_NUM,
                ERRMSG_WRONG_PARAM_NUM(ppool.size(), datas.size())};
        for(int i = 0; i < ppool.size(); i++) set_var(ppool[i], datas[i]);

        return;
    }

    Data RTE::param_eval(RTES* rtes, signed int pn)
    {
        // printf(" pe\n");
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
        // printf(" pe %s\n", pid.c_str());
        Data data = eval_node(rtes, p);
        set_var(pid, data);

        return data;
    }

    std::vector<Data> RTE::params_eval(RTES* rtes)
    {
        std::vector<Data> datas;
        for(int i = 0; i < ppool.size(); i++)
            datas.push_back(param_eval(rtes, i));

        return datas;
    }

    Data RTE::eval_data(RTES* rtes, Data data)
    {
        switch(data.dtype)
        {
            case DataType::NUMBER:
            case DataType::BOOLEAN:
                return data;

            case DataType::FUNCTION:
                return eval_rte(rtes, data.d.fval);

            case DataType::UNKNOWN:
            default:
                return data;
        }
    }

    Data RTE::eval_var(RTES* rtes, const std::string id)
    {
        // printf(">> eval var %s\n", id.c_str());
        return eval_data(rtes, rtes->get_var(id));
    }

    Data RTE::eval_node(RTES* rtes, ExpNode* node)
    {
        // printf("en %p\n", node);
        if(node->ntype == NodeType::LIT)
             return eval_data(rtes, ((LitNode*)node)->data);
        else return eval_var(rtes, ((VarNode*)node)->vid);
    }

    void RTE::init()
    {
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

        return rtev.rbegin()[from_back % rtev.size()];
    }

    Data RTES::eval(RTE* rte)
    {
        return RTE::eval_rte(this, rte);
    }

    void RTES::init()
    {
        rtev.clear();

        return;
    }
}

namespace mnlsp::utl
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

    std::vector<std::string> str_split(const std::string str, const std::string delimiter)
    {
        std::vector<std::string> strs;
        size_t last = 0;
        size_t next = 0;
        while((next = str.find(delimiter, last)) != std::string::npos)
        {
            strs.push_back(str.substr(last, next - last));
            last = next + delimiter.length();
        }
        strs.push_back(str.substr(last));

        return strs;
    }

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

    std::vector<ExpNode*>* v_new()
    {
        return new std::vector<ExpNode*>();
    }

    void v_concat(std::vector<ExpNode*>* v1, std::vector<ExpNode*>* v2)
    {
        v1->insert(v1->end(), v2->begin(), v2->end());

        return;
    }
}

namespace mnlsp::bif
{
    int lambda_index = 0;

    Data _(RTES* rtes)
    {
        rtes->get_rte(0)->params_eval(rtes);

        return Data();
    }

    Data _print_num(RTES* rtes)
    {
        // printf("> pn\n");
        // Number of params has been check in parsing
        Data d = rtes->get_rte(0)->params_eval(rtes)[0];

        if(d.dtype != DataType::NUMBER)
            throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::NUMBER, d.dtype)};

        fprintf(stdout, "%d\n", d.d.ival);

        return Data();
    }

    Data _print_bool(RTES* rtes)
    {
        Data d = rtes->get_rte(0)->params_eval(rtes)[0];

        if(d.dtype != DataType::BOOLEAN)
            throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::BOOLEAN, d.dtype)};

        fprintf(stdout, "%s\n", d.d.bval ? "#t" : "#f");

        return Data();
    }

    Data _plus(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

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

    Data _minus(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        for(Data d : datas)
            if(d.dtype != DataType::NUMBER)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::NUMBER, d.dtype)};

        return Data(datas[0].d.ival - datas[1].d.ival);
    }

    Data _multiply(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        int n = 1;
        for(Data d : datas)
        {
            if(d.dtype != DataType::NUMBER)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::NUMBER, d.dtype)};
            n *= d.d.ival;
        }

        return Data(n);
    }

    Data _divide(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        for(Data d : datas)
            if(d.dtype != DataType::NUMBER)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::NUMBER, d.dtype)};

        return Data(datas[0].d.ival / datas[1].d.ival);
    }

    Data _modulus(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        for(Data d : datas)
            if(d.dtype != DataType::NUMBER)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::NUMBER, d.dtype)};

        return Data(datas[0].d.ival % datas[1].d.ival);
    }

    Data _greater(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        for(Data d : datas)
            if(d.dtype != DataType::NUMBER)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::NUMBER, d.dtype)};

        return Data(datas[0].d.ival > datas[1].d.ival);
    }

    Data _smaller(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        for(Data d : datas)
            if(d.dtype != DataType::NUMBER)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::NUMBER, d.dtype)};

        return Data(datas[0].d.ival < datas[1].d.ival);
    }

    Data _equal(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        for(Data d : datas)
            if(d.dtype != DataType::NUMBER)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::NUMBER, d.dtype)};

        return Data(datas[0].d.ival == datas[1].d.ival);
    }

    Data _and(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        bool b = true;
        for(Data d : datas)
        {
            if(d.dtype != DataType::BOOLEAN)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::BOOLEAN, d.dtype)};
            b = b && d.d.bval;
        }

        return Data(b);
    }

    Data _or(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        bool b = false;
        for(Data d : datas)
        {
            if(d.dtype != DataType::BOOLEAN)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::BOOLEAN, d.dtype)};
            b = b || d.d.bval;
        }

        return Data(b);
    }

    Data _not(RTES* rtes)
    {
        std::vector<Data> datas = rtes->get_rte(0)->params_eval(rtes);

        for(Data d : datas)
            if(d.dtype != DataType::BOOLEAN)
                throw (ErrPkt){ErrType::TYPE_ERR,
                    ERRMSG_TYPE_ERR(DataType::BOOLEAN, d.dtype)};

        return Data(!datas[0].d.bval);
    }

    Data _define(RTES* rtes)
    {
        RTE* crte = rtes->get_rte(0);
        std::string id = ((VarNode*)crte->get_params()[0])->vid;
        Data d = crte->param_eval(rtes, 1);
        if(d.dtype == DataType::UNKNOWN)
            throw (ErrPkt){ErrType::VAR_UNKNOWN,
                ERRMSG_VAR_UNKNOWN(id)};
        rtes->get_rte(1)->new_var(id, d);

        return Data();
    }

    Data _fun(RTES* rtes)
    {
        // printf(">> fun\n");
        RTE* crte = rtes->get_rte(0);
        // Format: _p_<name1>_<name2>
        std::vector<std::string> ids;
        std::vector<ExpNode*> params;
        // crte->get_params()[1];
        // printf("<>\n");
        if(crte->get_var("_p").d.ival == 3)  // Handle define
        {
            crte->param_eval(rtes, 0);
            if(((VarNode*)crte->get_params()[1])->vid.size() >= 3)
                ids = utl::str_split(
                    ((VarNode*)crte->get_params()[1])->vid.substr(3), "_");
            params.push_back(crte->get_params()[2]);
        }
        else
        {
            if(((VarNode*)crte->get_params()[0])->vid.size() >= 3)
                ids = utl::str_split(
                    ((VarNode*)crte->get_params()[0])->vid.substr(3), "_");
            params.push_back(crte->get_params()[1]);
        }
        // printf("><> %s %d\n", ((VarNode*)crte->get_params()[0])->vid.c_str(), ids.size());
        // printf("<>< %s %s\n", ids[0].c_str(), ids[1].c_str());

        RTE* rte = RTE::get_lit_fun_rte(crte, ids, params);
        // printf(">> %d\n", rte->get_ppool().size());
        // crte->get_ppool().assign(ids.begin(), ids.end());
        // for(std::string id : ids) crte->new_var(id, Data());
        // RTE* orte = RTE::get_var_fun_rte(
        //     "_foo_" + std::to_string(lambda_index),
        //     std::vector({new ExpNode(new Data(rte))}));
        // orte->set_ppool(rte->get_ppool());
        // orte->params_match(datas);

        // printf("<><>\n");

        return Data(rte);
    }

    Data _fun_call(RTES* rtes)
    {
        // printf(">>> fun call\n");
        RTE* crte = rtes->get_rte(0);
        // printf(">>>1\n");
        std::vector<std::string> pids = crte->get_ppool();
        std::vector<Data> datas;
        for(int i = 1; i < pids.size(); i++)
        {
            Data d = crte->param_eval(rtes, i);
            if(d.dtype == DataType::UNKNOWN)
                throw (ErrPkt){ErrType::VAR_UNKNOWN,
                    ERRMSG_VAR_UNKNOWN(pids[i])};
            datas.push_back(d);
        }
        // printf(">>>2 %d\n");
        RTE* frte;
        if(crte->get_params()[0]->ntype == NodeType::VAR)
        {
            std::string id = ((VarNode*)crte->get_params()[0])->vid;
            frte = rtes->get_var(id).d.fval;

        }
        else
        {
            frte = crte->param_eval(rtes, 0).d.fval;
        }
        // crte->get_ppool().assign(frte->get_ppool().begin(), frte->get_ppool().end());
        crte->set_ppool(frte->get_ppool());
        // for(std::string s : crte->get_ppool()) printf(">%s<\n", s.c_str());
        for(std::string pid : frte->get_ppool()) crte->new_var(pid, Data());
        crte->params_match(datas);
        // printf("<<<\n");
        // rte->ppool.insert(rte->ppool.end(), pids.begin(), pids.end());

        return frte->eval(rtes);
    }

    Data _if(RTES* rtes)
    {
        RTE* crte = rtes->get_rte(0);
        Data d = crte->param_eval(rtes, 0);
        if(d.dtype != DataType::BOOLEAN)
            throw (ErrPkt){ErrType::TYPE_ERR,
                ERRMSG_TYPE_ERR(DataType::BOOLEAN, d.dtype)};
        
        if(d.d.bval) return crte->param_eval(rtes, 1);
        else         return crte->param_eval(rtes, 2);
    }
}
