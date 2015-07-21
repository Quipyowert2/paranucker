/*
 *  Copyright (C) 2015  Andrei Karas
 *
 *  This file is part of Paranoid null checker.
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

#include "includes/parserincludes.h"

parserDefine(ParmDecl);

#include "parsers/base/decl.h"

#include "nodes/decl/parm_decl.h"

namespace Generic
{

void parseParmDeclNode(ParmDeclNode *node)
{
    fillType(node);
    fillLocation(node);
    fillDeclLabel(node);
    setPrintField(node, DECL_REGISTER, isRegister);
    setPrintField(node, TREE_USED, isUsed);

    Log::dump(node);

    fillDeclAutoGenerated(node);

    if (node->parseChilds <= 0)
        return;

    fillDeclAttributes(node);

    node->declType = static_cast<TypeNode*>(createParseNode(
        node,
        DECL_ARG_TYPE(node->gccNode),
        "decl type"));
    node->parmSize = static_cast<IntegerCstNode*>(createParseNode(
        node,
        DECL_SIZE(node->gccNode),
        INTEGER_CST,
        "parm size"));
}

}
