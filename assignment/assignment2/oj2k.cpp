//加密解密
//要求：输入一个6位数，加密后输出，再解密输出
#include <iostream>
#include <string>

using namespace std;
//K终于过了，oj跟字符串有什么仇

string encrypt(int plainText) {
    
    string encrypted = "";
    
    for(int i = 0; i < 6; i++) {
        int num = plainText % 10;
        int encryptedText = (num + 7) % 10;
        encrypted = encrypted + to_string(encryptedText);
        plainText /= 10;
    }
    
    return encrypted;
}

void decrypt(string encrypted) {
    
    cout << "解密：";
    
    for(int i = 5; i >= 0; --i) {
        int decryptedText = (encrypted[i]-'0'+3) % 10;
        cout<< decryptedText ;
    }
    
    cout << endl;
}

int main() {
    int plainText;
    
    while(cin>>plainText) {
        
        if(plainText>=100000 && plainText<=999999){
        
        string encrypted = encrypt(plainText);
        
        cout <<"加密：";

        for(int i = 0; i <6; ++i){
            cout<< encrypted[i] - '0' ;
        }
        
        cout<<endl;

        decrypt(encrypted);
        }
        
        else{
        
        cout<<"输入错误，退出程序。"<<endl;
        
        }
    }
}