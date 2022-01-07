#include"mnlsp.hpp"


namespace mnlsp
{
    RTE* RTE::get_base_rte()
    {
        // TODO: Inject builtin functions (only for root)
        RTEOtions rteo;  // Initial value

        RTE* rte = new RTE(rteo);
        RTE* trte;
        trte = rte->new_bif("_add", rteo, _add);
        trte->add_param("_p-0");
        trte->add_param("_p-0");

        return rte;
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
                // TODO: Error handle
                return data;
        }
    }

    Data RTE::eval_var(RTES* rtes, const std::string id)
    {
        Data data;
        rtes->get_var(id, &data);
        
        return eval_data(rtes, data);
    }

    Data RTE::eval_node(RTES* rtes, ExpNode* node)
    {
        if(node->ntype == NodeType::LIT)
             return eval_data(rtes, ((LitNode*)node)->data);
        else return eval_var(rtes, ((VarNode*)node)->vid);
    }

    RTE::RTE(RTEOtions rteo)
    {
        this->rteo = rteo;
        init();
    }

    ErrType RTE::init()
    {
        bif = nullptr;
        vpool.clear();

        new_var("_v");
        new_var("_p", 0);

        return ErrType::NOERR;
    }

    ErrType RTE::new_var(const std::string id, const Data data)
    {
        if(vpool.count(id)) return ErrType::REDEFINE;
        vpool[id] = new Data(data);

        return ErrType::NOERR;
    }

    ErrType RTE::new_var(const std::string id, int ival)
    {
        Data data;
        data.dtype = DataType::NUMBER;
        data.d.ival = ival;

        return new_var(id, data);
    }

    ErrType RTE::new_var(const std::string id)
    {
        Data data;
        data.dtype = DataType::UNKNOWN;

        return new_var(id, data);
    }

    ErrType RTE::has_var(const std::string id)
    {
        return vpool.find(id) == vpool.end() ? ErrType::VAR_NOT_FOUND : ErrType::NOERR;
    }
    
    ErrType RTE::get_var(const std::string id, Data* data)
    {
        auto it = vpool.find(id);
        if(it == vpool.end()) return ErrType::VAR_NOT_FOUND;
        *data = *((*it).second);

        return ErrType::NOERR;
    }

    ErrType RTE::set_var(const std::string id, const Data data)
    {
        if(has_var(id) == ErrType::NOERR)
        {
            *(vpool[id]) = data;
        }
        else return ErrType::VAR_NOT_FOUND;
    }

    ErrType RTE::set_var(const std::string id, int ival)
    {
        Data data;
        data.dtype = DataType::NUMBER;
        data.d.ival = ival;

        return set_var(id, data);
    }

    void RTE::add_param(const std::string id)
    {
        // TODO: Inject params
        // TODO: Inject eval variable
        // TODO: Inject options

        ppool.push_back(id);
        new_var(id);
        set_var("_p", ppool.size());

        return;
    }

    void RTE::add_params(std::vector<std::string> ids)
    {
        for(std::string id : ids)
        {
            ppool.push_back(id);
            new_var(id);
        }
        new_var("_p", ppool.size());

        return;
    }

    ErrType RTE::get_all_params(std::vector<Data>* datas)
    {
        Data data;
        for(std::string id : ppool)
        {
            get_var(id, &data);
            datas->push_back(data);
        }

        return ErrType::NOERR;
    }

    RTE* RTE::new_bif(const std::string id, RTEOtions rteo, ErrType (*bif)(RTES* rtes))
    {
        RTE* rte = new RTE(rteo);
        rte->bif = bif;
        Data data;
        data.dtype = DataType::FUNCTION;
        data.d.fval = rte;

        new_var(id, data);

        return rte;
    }

    Data RTE::eval(RTES* rtes)
    {
        rtes->enter_env(this);
        if(bif != nullptr)
        {
            bif(rtes);
        }
        else
        {
            // TO[DONE]DO
            // Bind to parameters literal name and do the body
            // Params cross RTE
            set_var("_v", eval_node(rtes, fun));
        }
        Data data;
        get_var("_v", &data);
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

    RTES::RTES()
    {
        init();
    }

    ErrType RTES::new_var(const std::string id, const Data data)
    {
        // Data data;
        // if(node->ntype == NodeType::LIT)
        // {
        //     data = ((LitNode*)node)->data;
        // }
        // else
        // {
        //     if(get_var(id, &data) != ErrType::NOERR); // TODO: Error handle
        // }

        return rtev.back()->new_var(id, data);
    }

    ErrType RTES::new_var(const std::string id, int ival)
    {
        Data data;
        data.dtype == DataType::NUMBER;
        data.d.ival = ival;

        return new_var(id, data);
    }

    ErrType RTES::has_var(const std::string id)
    {
        for(auto it = rtev.rbegin(); it != rtev.rend(); it++)
        {
            if((*it)->has_var(id) == ErrType::NOERR)
                return ErrType::NOERR;
        }

        return ErrType::VAR_NOT_FOUND;
    }

    ErrType RTES::get_var(const std::string id, Data* data)
    {
        for(auto it = rtev.rbegin(); it != rtev.rend(); it++)
        {
            if((*it)->get_var(id, data) == ErrType::NOERR)
                return ErrType::NOERR;
        }

        return ErrType::VAR_NOT_FOUND;
    }

    ErrType RTES::set_var(const std::string id, const Data data)
    {
        for(auto it = rtev.rbegin(); it != rtev.rend(); it++)
        {
            if((*it)->has_var(id) == ErrType::NOERR)
                return (*it)->set_var(id, data);
        }

        return ErrType::VAR_NOT_FOUND;
    }

    ErrType RTES::set_var(const std::string id, int ival)
    {
        Data data;
        data.dtype == DataType::NUMBER;
        data.d.ival = ival;

        return set_var(id, data);
    }

    ErrType RTES::enter_env(RTE* rte)
    {
        rtev.push_back(rte);

        return ErrType::NOERR;
    }

    ErrType RTES::leave_env()
    {
        if(rtev.size() <= 0) return ErrType::VOID_PRG;
        rtev.pop_back();

        return ErrType::NOERR;
    }

    ErrType RTES::get_rte(unsigned int from_back, RTE* rte)
    {
        rte = rtev.end()[((-from_back + 1) % rtev.size()) - 1];

        return ErrType::NOERR;
    }

    ErrType RTES::init()
    {
        rtev.clear();

        return ErrType::NOERR;
    }

    ErrType _add(RTES* rtes)
    {
        // Params: _p-0, _p-1, ...
        // var("_v").set(var("_p-0").get() + get_var("_p-1").get())

        RTE* crte;
        rtes->get_rte(1, crte);
        crte->params_eval(rtes);

        std::vector<Data> datas;
        crte->get_all_params(&datas);

        int n = 0;
        for(Data d : datas)
        {
            if(d.dtype != DataType::NUMBER);  // TODO; Type checking
            n += d.d.ival;
        }
        rtes->set_var("_v", n);

        return ErrType::NOERR;
    }
}
