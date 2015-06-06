/*
 *  Copyright (C) 2015  Andrei Karas
 *
 *  This file is part of AstDumper.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "parsers/parserincludes.h"

parserDefine(FunctionDecl);

#include "parsers/base/decl.h"

#include "nodes/function_decl.h"
#include "nodes/result_decl.h"

namespace Generic
{

void parseFunctionDeclNode(FunctionDeclNode *node)
{
    fillType(node);
    fillLocation(node);
    fillDeclLabel(node);
    Log::log(node);

    fillDeclAutoGenerated(node);
    setPrintField(node, DECL_FUNCTION_VERSIONED, hasTargets);
    setPrintField(node, DECL_VIRTUAL_P, isVirtual);
    setPrintField(node, DECL_FINAL_P, isFinal);
    setPrintField(node, TREE_READONLY, isConst);
    setPrintField(node, DECL_PURE_P, isPure);

    fillDeclAttributes(node);
    node->functionType = static_cast<FunctionTypeNode*>(createParseNode(
        node,
        TREE_TYPE(node->gccNode),
        FUNCTION_TYPE,
        "function type"));
    node->result = static_cast<ResultDeclNode*>(createParseNode(
        node,
        DECL_RESULT(node->gccNode),
        RESULT_DECL,
        "function result"));
    FOR_CHAIN(node->gccNode, it, DECL_ARGUMENTS, DECL_CHAIN)
    {
        node->args.push_back(static_cast<ParmDeclNode*>(
            createParseNode(node, it, PARM_DECL, "argument")));
    }
    node->code = createParseNode(
        node,
        DECL_SAVED_TREE(node->gccNode),
        "code");
    node->target = createParseNode(
        node,
        DECL_FUNCTION_SPECIFIC_TARGET(node->gccNode),
        "target");
    node->optimisation = createParseNode(
        node,
        DECL_FUNCTION_SPECIFIC_OPTIMIZATION(node->gccNode),
        "optiomisations");
}

}
