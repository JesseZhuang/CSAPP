#include "gtest/gtest.h"
#include "ood/ExcelSumFormula.hpp"

#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>

using namespace std;

namespace {

using Arg = variant<int, string, vector<string>>;
using Cmd = pair<string, vector<Arg>>;

optional<int> run_cmd(lc631::Solution &sheet, const Cmd &cmd) {
    const string &op = cmd.first;
    const vector<Arg> &args = cmd.second;
    if (op == "set") {
        sheet.set(get<int>(args.at(0)), get<string>(args.at(1)), get<int>(args.at(2)));
        return nullopt;
    }
    if (op == "get") {
        return optional<int>(sheet.get(get<int>(args.at(0)), get<string>(args.at(1))));
    }
    if (op == "sum") {
        vector<string> nums;
        const auto &v = get<vector<string>>(args.at(2));
        nums.assign(v.begin(), v.end());
        return optional<int>(
            sheet.sum(get<int>(args.at(0)), get<string>(args.at(1)), std::move(nums)));
    }
    return nullopt;
}

optional<int> run_cmd(lc631::Solution2 &sheet, const Cmd &cmd) {
    const string &op = cmd.first;
    const vector<Arg> &args = cmd.second;
    if (op == "set") {
        sheet.set(get<int>(args.at(0)), get<string>(args.at(1)), get<int>(args.at(2)));
        return nullopt;
    }
    if (op == "get") {
        return optional<int>(sheet.get(get<int>(args.at(0)), get<string>(args.at(1))));
    }
    if (op == "sum") {
        vector<string> nums;
        const auto &v = get<vector<string>>(args.at(2));
        nums.assign(v.begin(), v.end());
        return optional<int>(
            sheet.sum(get<int>(args.at(0)), get<string>(args.at(1)), std::move(nums)));
    }
    return nullopt;
}

template <typename ExcelT>
void verify(const vector<string> &commands,
            const vector<vector<Arg>> &arguments,
            const vector<optional<int>> &expected) {
    vector<optional<int>> result;
    unique_ptr<ExcelT> sheet;
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "Excel") {
            const auto &a = arguments[i];
            sheet = make_unique<ExcelT>(get<int>(a.at(0)), get<string>(a.at(1)));
            result.push_back(nullopt);
        } else {
            Cmd cmd{commands[i], arguments[i]};
            result.push_back(run_cmd(*sheet, cmd));
        }
    }
    ASSERT_EQ(expected.size(), result.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        ASSERT_EQ(expected[i].has_value(), result[i].has_value());
        if (expected[i].has_value()) {
            ASSERT_EQ(*expected[i], *result[i]);
        }
    }
}

} // namespace

template <typename ExcelT>
static void run_excel_sum_formula_cases() {
    {
        vector<string> commands{"Excel", "set", "sum", "set", "get"};
        vector<vector<Arg>> args{{3, string{"C"}},
                                 {1, string{"A"}, 2},
                                 {3, string{"C"}, vector<string>{"A1", "A1:B2"}},
                                 {2, string{"B"}, 2},
                                 {3, string{"C"}}};
        vector<optional<int>> want{nullopt, nullopt, 4, nullopt, 6};
        verify<ExcelT>(commands, args, want);
    }
    {
        vector<string> commands{"Excel", "set", "set", "sum", "get", "set", "set", "get"};
        vector<vector<Arg>> args{{2, string{"C"}},
                                 {1, string{"A"}, 5},
                                 {1, string{"B"}, 3},
                                 {2, string{"C"}, vector<string>{"A1:B1"}},
                                 {2, string{"C"}},
                                 {2, string{"C"}, 100},
                                 {1, string{"A"}, 20},
                                 {2, string{"C"}}};
        vector<optional<int>> want{nullopt, nullopt, nullopt, 8, 8, nullopt, nullopt, 100};
        verify<ExcelT>(commands, args, want);
    }
    {
        vector<string> commands{"Excel", "set", "set", "sum", "sum", "get", "sum", "get", "set", "get",
                                "get", "set", "get", "get"};
        vector<vector<Arg>> args{{2, string{"D"}},
                                 {1, string{"A"}, 2},
                                 {1, string{"B"}, 3},
                                 {1, string{"C"}, vector<string>{"A1", "A1:B1"}},
                                 {2, string{"A"}, vector<string>{"C1", "B1"}},
                                 {2, string{"A"}},
                                 {1, string{"C"}, vector<string>{"B1"}},
                                 {2, string{"A"}},
                                 {1, string{"A"}, 10},
                                 {1, string{"C"}},
                                 {2, string{"A"}},
                                 {1, string{"B"}, 5},
                                 {1, string{"C"}},
                                 {2, string{"A"}}};
        vector<optional<int>> want{nullopt, nullopt, nullopt, 7, 10, 10, 3, 6, nullopt, 3, 6,
                                   nullopt, 5, 10};
        verify<ExcelT>(commands, args, want);
    }
    {
        vector<string> commands{"Excel", "set", "set", "set", "set", "sum", "set", "get"};
        vector<vector<Arg>> args{{3, string{"D"}},
                                 {1, string{"A"}, 1},
                                 {1, string{"B"}, 2},
                                 {2, string{"A"}, 3},
                                 {2, string{"B"}, 4},
                                 {3, string{"D"}, vector<string>{"A1:B2", "B1:B2"}},
                                 {2, string{"B"}, 5},
                                 {3, string{"D"}}};
        vector<optional<int>> want{nullopt, nullopt, nullopt, nullopt, nullopt, 16, nullopt, 18};
        verify<ExcelT>(commands, args, want);
    }
}

TEST(ood, excel_sum_formula_cached) {
    run_excel_sum_formula_cases<lc631::Solution>();
}

TEST(ood, excel_sum_formula_lazy) {
    run_excel_sum_formula_cases<lc631::Solution2>();
}
