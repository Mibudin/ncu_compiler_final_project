#pragma once
#ifndef MNLSP_HPP
#define MNLSP_HPP

#include<iostream>
#include<string>
#include<vector>


namespace mnlsp
{
    struct Fun;

    union Data
    {
        int ival;
        bool bval;
        Fun* fval;
    };

    enum class NodeType : int
    {
        LIT, VAR
    };

    enum class DataType : int
    {
        NUMBER, BOOLEAN, FUNCTION
    };

    struct ExpNode
    {
        NodeType ntype;
        DataType dtype;
        unsigned char _[]; // TODO
    };

    struct LitNode
    {
        const NodeType ntype = NodeType::LIT;
        DataType dtype;
        Data data;
    };

    struct VarNode
    {
        const NodeType ntype = NodeType::VAR;
        DataType dtype;
        std::string id;
    };

    struct Fun
    {
        std::vector<VarNode> params;  // Handle scope and closure (keep env)
        ExpNode* node;
    };

    /**
     * Pool:
     * - Builtin function pool
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
}

#define YYSTYPE mnlsp::ExpNode

#endif
