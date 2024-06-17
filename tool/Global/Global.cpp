#include "Global.h"

QString removeSpace(QString str) 
{
    QString ans="";
    for(int i=0;i<str.length();i++){
        if(str[i]!=' '){
            ans+=str[i];
        }
        else{
             continue;
        }
    }
    return ans;
}

bool isProperId(QString str)
{
    if(str.length() != 6){
        return false;
    }
    else{
        QByteArray ba = str.toLatin1();
        const char *s = ba.data();
        while(*s && *s>='0' && *s<='9'){
            s++;
        }
        if (*s){ 
            return false;
        }
        else{ 
            return true;
        }
    }
}

bool isProperPassword(QString str)
{
    if(str.length()>=6 && str.length()<=20){
        return true;
    }
    else{
         return false;
    }
}
















