//  checksum updated
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    char a[20], b[20];
    char sum[20], complement[20];
    int i, length;
    
	cout << "Enter first binary string\n";
    cin >> a;
    
    cout << "Enter second binary string\n";
    cin >> b;
    
    if(strlen(a) == strlen(b))
    {
		length = strlen(a);
		char carry='0';
        
		for(i = length - 1; i >= 0; i--)
        {
			if(a[i] == '0' && b[i] == '0')
				if(carry == '0')
		            sum[i] = '0';
		        else	
		            sum[i] = '1', carry = '0';
            else if(a[i] == '0' && b[i] == '1')
            	if(carry == '0')
		            sum[i] = '1';
		        else
		            sum[i] = '0';
            else if(a[i] == '1' && b[i] == '0')
            	if(carry == '0')
                	sum[i] = '1';
                else
                	sum[i] = '0';
            else if(a[i] == '1' && b[i] == '1')
            	if(carry == '0')
		        {
		            sum[i] = '0';
		            carry = '1';
		        }
            	else
                	sum[i] = '1';
            else
                break;
        }
        
        sum[length] = '\0';
		cout << "Sum is " << carry << sum << endl;
		
		for(i = 0; i < length; i++)
        {
            if(sum[i] == '0')
                complement[i] = '1';
            else
                complement[i] = '0';
        }
        
        if(carry == '1')
            carry = '0';
        else
            carry = '1';
        
        complement[length] = '\0';
		cout << "Complement is " << carry << complement << endl;
	}
	else 
		cout << "Wrong input strings" << endl;
	
	return 0;
}
