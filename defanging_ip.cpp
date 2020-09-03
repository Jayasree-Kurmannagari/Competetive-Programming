//Leetcode
//Problem Defanging an IP Address
//<a href="https://leetcode.com/problems/defanging-an-ip-address/">

class Solution {
public:
    string defangIPaddr(string address) {
       string defangIP("");
        for(char c: address)
            (c=='.')? defangIP+="[.]":defangIP+=c;
        return defangIP;
    }
};
