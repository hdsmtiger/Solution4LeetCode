class Solution {
public:

    
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        
        int length = s.size();
        
        if(length == 0)
        return 0;
        
        int n1=0, n2=0;
        if(s.at(0) != '0')
            n2 = 1;
        n1 = n2;
        for(int i=1; i<length; i++)
        {
            int n3=0;
            if(s.at(i) != '0')
                n3 = n2;
            
            if(s.at(i-1)=='1' && s.at(i) <='9' || s.at(i-1)=='2' && s.at(i) <='6')
                n3 += n1;
            
            n1 = n2;
            n2 = n3;
        }
            
        return n2;
    }
};
