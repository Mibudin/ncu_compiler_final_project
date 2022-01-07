#pragma once
#ifndef MNLSP_HPP
#define MNLSP_HPP

#include<iostream>
#include<string>
#include<vector>
#include<map>

// TODO: `_define` need the 2nd top RTE
// TODO: `_if`, `_define` not eval first


namespace mnlsp
{
    enum class ErrType : int
    {
        NOERR = 0, REDEFINE, VAR_NOT_FOUND, VOID_PRG
    };

    enum class NodeType : int
    {
        LIT, VAR
    };

    enum class DataType : int
    {
        UNKNOWN = 0, NUMBER, BOOLEAN, FUNCTION
    };

    struct RTE;  // Forward declaration

    struct Data
    {
        DataType dtype;
        union
        {
            int ival;
            bool bval;
            RTE* fval;
        } d;
    };

    typedef std::map<std::string, Data*> VarPool;

    struct ExpNode
    {
        NodeType ntype;
        unsigned char _[24]; // TODO
    };

    struct LitNode
    {
        const NodeType ntype = NodeType::LIT;
        Data data;
        unsigned char _[20];
    };

    struct VarNode
    {
        const NodeType ntype = NodeType::VAR;
        std::string vid;
    };

    struct RTEOtions
    {
        // bool pre_eval = true;
        bool param_num_uncertain = false;
    };

    class RTES;  // Forward declaration

    class RTE
    {
    public:
        static RTE* get_base_rte();
        static Data eval_data(RTES* rtes, Data data);
        static Data eval_var(RTES* rtes, const std::string id);
        static Data eval_node(RTES* rtes, ExpNode* node);
        RTE(RTEOtions rteo);
        ErrType init();
        ErrType new_var(const std::string id, const Data data);
        ErrType new_var(const std::string id);
        ErrType new_var(const std::string id, int ival);
        ErrType has_var(const std::string id);
        ErrType get_var(const std::string id, Data* data);
        ErrType set_var(const std::string id, const Data data);
        ErrType set_var(const std::string id, int ival);
        void add_param(const std::string id);
        void add_params(std::vector<std::string> params);
        ErrType get_all_params(std::vector<Data>* datas);
        RTE* new_bif(const std::string id, RTEOtions rteo, ErrType (*bif)(RTES* rtes));
        Data eval(RTES* rtes);
        void param_eval(RTES* rtes, signed int pn);
        void params_eval(RTES* rtes);
    private:
        RTEOtions rteo;
        // Variable pool
        // Handle scope and closure (keep env)
        VarPool vpool;  // Data types are unkown until being called
        std::vector<std::string> ppool;
        ExpNode* fun;
        std::vector<ExpNode*> params;
        ErrType (*bif)(RTES* rtes);
    };

    class RTES
    {
    public:
        RTES();
        ErrType new_var(const std::string id, const Data data);
        ErrType new_var(const std::string id, int ival);
        ErrType has_var(const std::string id);
        ErrType get_var(const std::string id, Data* data);
        ErrType set_var(const std::string id, const Data data);
        ErrType set_var(const std::string id, int ival);
        ErrType enter_env(RTE* rte);
        ErrType leave_env();
        ErrType get_rte(unsigned int from_back, RTE* rte);
    private:
        std::vector<RTE*> rtev;
        ErrType init();
    };

    /**
     * Pool:
     * - Builtin variable pool
     * - Variable pool
     */

    /**
     * Builtin Function Implementing:
     * 
     * - print-num
     * - print-bool
     * 
     * - plus
     * - minus
     * - multiply
     * - divide
     * - modulus
     * - greater
     * - smaller
     * - equal
     * 
     * - and
     * - or
     * - not
     * 
     * - define
     * 
     * - fun/lambda
     * 
     * - if
     */

    /**
     * Special Generated Variables:
     * - Prohram entry: _
     * - Builtin functions: _<fun name>, ...
     * - Num of params: _p
     * - Params for builtin functions: _p-0, _p-1, ...
     * - RTE eval variable: _v
     * - Options: _o-<option name>, ...
     */

    /**
     * Options:
     * - Dynamic scope?
     */

    ErrType _add(RTES* rtes);
    ErrType _define(RTES* rtes);


    // TODO: Program Run Time Environment
    extern RTE prte;
}

#define YYSTYPE mnlsp::ExpNode

#endif
