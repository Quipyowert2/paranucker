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

#include "includes/parserincludes.h"

parserDefine(LoopExpr);

#include "parsers/base/expr.h"

#include "nodes/expr/loop_expr.h"

namespace Generic
{

void parseLoopExprNode(LoopExprNode *node)
{
    fillType(node);
    Log::log(node);

//    fillExprOperands(node);

    node->body = createParseNode(
        node,
        LOOP_EXPR_BODY(node->gccNode),
        "body");
}

}
