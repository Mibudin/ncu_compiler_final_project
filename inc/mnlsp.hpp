#pragma once
#ifndef MNLSP_HPP
#define MNLSP_HPP

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<memory>
#include<stdexcept>

// TODO: `_define` need the 2nd top RTE
// TODO: `_if`, `_define` not eval first
// TODO: define strings


namespace mnlsp
{
    #define ERRMSG_REDEFINE(_vid) (mnlsp::utl::strf( \
        "[REDEFINE] Error: " \
        "The variable `%s` has deen defined.", \
        _vid.c_str()))
    #define ERRMSG_VAR_NOT_FOUND(_vid) (mnlsp::utl::strf( \
        "[VAR_NOT_FOUND] Error: " \
        "The variable `%s` cannot be found in the current RTE.", \
        _vid.c_str()))
    #define ERRMSG_VAR_NOT_FOUND_G(_vid) (mnlsp::utl::strf( \
        "[VAR_NOT_FOUND_G] Error: " \
        "The variable `%s` cannot be found in all RTEs.", \
        _vid.c_str()))
    #define ERRMSG_NO_MORE_RTE (mnlsp::utl::strf( \
        "[NO_MORE_RTE] Error: " \
        "There is no more RTE to be interacted with."))
    #define ERRMSG_TYPE_ERR(_expc, _real) (mnlsp::utl::strf( \
        "[TYPE_ERR] Error: " \
        "Expect `%s`, but get `%s`.", \
        mnlsp::utl::dtype_str(_expc).c_str(), \
        mnlsp::utl::dtype_str(_real).c_str()))
    #define ERRMSG_VAR_UNKNOWN(_vid) (mnlsp::utl::strf( \
        "[VAR_UNKNOWN] Error: " \
        "The variable `%s` cannot be unlnown.", \
        _vid.c_str()))
    #define ERRMSG_WRONG_PARAM_NUM(_expc, _real) (mnlsp::utl::strf( \
        "[WRONG_PARAM_NUM] Error: " \
        "Expect `%d`, but get `%d`.", \
        _expc, _real))


    enum class ErrType : int
    {
        NOERR = 0,
        REDEFINE,
        VAR_NOT_FOUND,
        VAR_NOT_FOUND_G,
        NO_MORE_RTE,
        TYPE_ERR,
        VAR_UNKNOWN,
        WRONG_PARAM_NUM,
    };

    struct ErrPkt
    {
        ErrType etype;
        std::string msg;  // TODO: Print default msg if empty
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
        Data() :
            dtype{DataType::UNKNOWN}  {}
        Data(int ival) :
            dtype{DataType::NUMBER}   {this->d.ival = ival;}
        Data(bool bval) :
            dtype{DataType::BOOLEAN}  {this->d.bval = bval;}
        Data(RTE* fval) :
            dtype{DataType::FUNCTION} {this->d.fval = fval;}

        DataType dtype;
        union
        {
            int ival;
            bool bval;
            RTE* fval;
        } d;
    };

    typedef std::map<std::string, Data*> VarPool;

    struct LitNode
    {
        const NodeType ntype = NodeType::LIT;
        Data data;
        unsigned char _[16];
    };

    struct VarNode
    {
        const NodeType ntype = NodeType::VAR;
        std::string vid;
    };

    struct ExpNode
    {
        ExpNode(){}
        ExpNode(Data data) :
            ntype{NodeType::LIT} {((LitNode*)this)->data = data;}
        // ExpNode(const char* vid) :
        //     ntype{NodeType::VAR} {((VarNode*)this)->vid = std::string(vid);}
        ExpNode(std::string vid, int _) :
            ntype{NodeType::VAR} {((VarNode*)this)->vid = vid;}

        NodeType ntype;
        unsigned char _[24]; // TODO
    };

    struct RTEOtions
    {
        // bool pre_eval = true;
        // bool param_num_uncertain = false;
        int _;  // TODO
    };

    struct YYType
    {
        YYType()=default;

        struct
        {
            RTE* r;
            std::vector<ExpNode*>* v;
            ExpNode* n;
            Data* d;
            std::string* s;
        } t;
    };


    class RTES;  // Forward declaration

    class RTE
    {
    public:
        static RTE* get_base_rte();
        static RTE* get_var_fun_rte(const std::string id, std::vector<ExpNode*> params);
        static RTE* get_lit_fun_rte(RTE* frte, const std::vector<std::string> pids,
                                    std::vector<ExpNode*> params);
        static Data eval_rte(RTES* rtes, RTE* rte);

        RTE();
        RTE(RTEOtions rteo);

        void new_var(const std::string id, const Data data);
        bool has_var(const std::string id);
        Data get_var(const std::string id);
        void set_var(const std::string id, const Data data);

        void set_fun(ExpNode* fun);

        void add_params(std::vector<std::string> ids, std::vector<ExpNode*> params);
        void add_params(std::vector<ExpNode*> params);
        std::vector<Data> get_all_params();
        std::vector<std::string> get_ppool();
        void set_ppool(std::vector<std::string> p);
        std::vector<ExpNode*> get_params();

        Data eval(RTES* rtes);
        void params_match(std::vector<Data> datas);
        Data param_eval(RTES* rtes, signed int pn);
        std::vector<Data> params_eval(RTES* rtes);

    private:
        static Data eval_data(RTES* rtes, Data data);
        static Data eval_var(RTES* rtes, const std::string id);
        static Data eval_node(RTES* rtes, ExpNode* node);

        RTEOtions rteo;
        VarPool vpool;
        std::vector<std::string> ppool;
        std::vector<ExpNode*> params;
        ExpNode* fun;
        Data (*bif)(RTES* rtes);

        void init();
        RTE* new_bif(const std::string id, RTEOtions rteo, Data (*bif)(RTES* rtes));
    };

    class RTES
    {
    public:
        RTES();

        void new_var(const std::string id, const Data data);
        bool has_var(const std::string id);
        Data get_var(const std::string id);
        void set_var(const std::string id, const Data data);

        void enter_env(RTE* rte);
        void leave_env();
        RTE* get_rte(unsigned int from_back);

        Data eval(RTE* rte);

    private:
        std::vector<RTE*> rtev;

        void init();
    };

    /**
     * Pool:
     * - Builtin variable pool
     * - Variable pool
     */

    /**
     * Builtin Function Implementing:
     * - _
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

    // From: https://stackoverflow.com/a/26221725
    RTES* mnlsp_init();

    namespace utl
    {
        template<typename ... Args>
        std::string strf(const std::string& format, Args ... args);
        std::vector<std::string> str_split(const std::string str, const std::string delimiter);
        std::string dtype_str(DataType dtype);

        std::vector<ExpNode*>* v_new();
        void v_concat(std::vector<ExpNode*>* v1, std::vector<ExpNode*>* v2);
    }

    namespace bif
    {
        extern int lambda_index;

        Data _          (RTES* rtes);

        Data _print_num (RTES* rtes);
        Data _print_bool(RTES* rtes);

        Data _plus      (RTES* rtes);
        Data _minus     (RTES* rtes);
        Data _multiply  (RTES* rtes);
        Data _divide    (RTES* rtes);
        Data _modulus   (RTES* rtes);
        Data _greater   (RTES* rtes);
        Data _smaller   (RTES* rtes);
        Data _equal     (RTES* rtes);

        Data _and       (RTES* rtes);
        Data _or        (RTES* rtes);
        Data _not       (RTES* rtes);

        Data _define    (RTES* rtes);

        Data _fun       (RTES* rtes);
        Data _fun_call  (RTES* rtes);

        Data _if        (RTES* rtes);
    }
}

#define YYSTYPE mnlsp::YYType

#endif
