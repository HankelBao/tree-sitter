#include "arithmetic.h"
#include "rules.h"

using namespace tree_sitter;
using namespace rules;

namespace test_grammars {
    Grammar arithmetic() {
        return Grammar({
            { "expression", choice({
                seq({
                    sym("term"),
                    sym("plus"),
                    sym("term") }),
                sym("term") }) },
            { "term", choice({
                seq({
                    sym("factor"),
                    sym("times"),
                    sym("factor") }),
                sym("factor") }) },
            { "factor", choice({
                sym("variable"),
                sym("number"),
                seq({
                    str("("),
                    sym("expression"),
                    str(")") }) }) },
            { "plus", str("+") },
            { "times", str("*") },
            { "number", pattern("\\d+") },
            { "variable", pattern("\\w+") },
        });
    }
}
