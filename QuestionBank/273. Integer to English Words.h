#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
        {
            return "Zero";
        }
        vector<string> units = { "","Thousand ","Million ","Billion " };
        vector<string> ones = { "", "One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine " };
        vector<string> tens_one = {"Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen " };
        vector<string> tens_other = { "","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety " };
        int index = 0;
        string result = "";
        while (num!=0)
        {
            int cur_thousand = num % 1000;
            if (cur_thousand!=0)
            {
                string cur_result = "";
                int hundred_num = cur_thousand / 100;
                int ten_num = cur_thousand / 10 % 10;
                int one_num = cur_thousand % 10;
                if (hundred_num != 0)
                {
                    cur_result += ones[hundred_num] + "Hundred ";
                }
                if (ten_num==1)
                {
                    cur_result += tens_one[one_num];
                }
                else
                {
                    cur_result += tens_other[ten_num] + ones[one_num];
                }
                cur_result += units[index];
                result = cur_result + result;
            }
            index++;
            num /= 1000;
        }
        if (result[result.size()-1]==' ')
        {
            result.pop_back();
        }
        return result;
    }
};