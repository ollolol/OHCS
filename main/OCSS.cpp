#include "../include/OCSS.h"

OCSS::OCSS()
{
    DMode = false;
    Char_List = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ `-=[]\\;',./~!@#$%^&*()_+{}|:\"<>?";
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
}

OCSS::~OCSS()
{
    //dtor
}
void OCSS::Encrypt(string& Data,vector<char>& Key)
{
    int last_key = 95;
    //if(DMode == true)
    //{printf("Base %d-\"%c\"||", 95, Char_List[94]);cout<<Data<<'\n';}
    for(char &plugin_key : Key)
    {
        int plugin_value = 0;
        //#pragma omp parallel for
        for (unsigned int values = 0; values < Char_List.length() ; values++)
        {
            if (Char_List[values] == plugin_key)
            {
                plugin_value = values;
                break;
            }
        }
        ToBase(Data, last_key, plugin_value);
        //if(DMode == true)
        //{printf("Base %d-\"%c\"||", plugin_value, Char_List[plugin_value - 1]);cout<<Data<<'\n';}
        unsigned int plugin_count = rand()%Data.length()/3+1;
        vector<unsigned int> plugin_location;
        while (plugin_count > 0)
        {
            plugin_location.push_back(rand()%Data.length());
            plugin_count--;
        }
        #pragma omp parallel for
        for(unsigned int& this_location : plugin_location)
        {
            string new_data = "";
            #pragma omp parallel for
            for (unsigned int x = 0; x < Data.length(); x++)
            {
                if (x == this_location)
                {
                    new_data += Char_List[plugin_value];
                }
                new_data += Data[x];
            }
            Data = new_data;
        }
        last_key = (int)(plugin_value + 1);
        //if(DMode == true)
        //{printf("Base %d-\"%c\"||", plugin_value + 1, Char_List[plugin_value]); cout<<Data<<'\n';}//Debug
    }
    ToBase(Data, last_key, 95);
    return;
}
void OCSS::Decrypt(string& Data,vector<char>& Key)
{
    int last_key = 95;
    reverse(Key.begin(), Key.end());
    //if(DMode == true)
    //{printf("Base %d-\"%c\"||", 95, Char_List[94]);cout<<Data<<'\n';}
    for(char remove_key : Key)
    {
        int remove_value = 0;
        #pragma omp parallel for
        for (unsigned int values = 0; values < Char_List.length(); values++)
        {
            if (Char_List[values] == remove_key)
            {
                remove_value = values;
                break;
            }
        }
        ToBase(Data, last_key, (int)(remove_value + 1));
        //if(DMode == true)
        //{printf("Base %d-\"%c\"||", remove_value + 1, Char_List[remove_value]);cout<<Data<<'\n';}
        replace( Data.begin(), Data.end(), remove_key, '\0');
        //if(DMode == true)
        //{printf("Base %d-\"%c\"||", remove_value, Char_List[remove_value - 1]);cout<<Data<<'\n';}
        last_key = remove_value;
    }
    ToBase(Data, last_key, 95);
}
void OCSS::ToBase(string& Data,int Original_Base,int New_Base)
{
    if (Original_Base == 0 || Original_Base == 1 || New_Base == 0 || New_Base == 1 || Data == "")
    {
        return;
    }
    vector<BigInteger> value;
    for(char& data : Data)
    {
        #pragma omp parallel for
        for (unsigned long values = 0; values < Char_List.length(); values++)
        {
            if (Char_List[values] == data)
            {
                value.push_back(values);
                break;
            }
        }
    }
        //data = value's value
    for(unsigned long x = 0; x < value.size(); x++)
    {
        //#pragma omp parallel for
        for(unsigned long y = 0; y < x; y++)
        {
            value[y] *= Original_Base;
        }
    }
    //update value: every on correct value
    BigInteger total_value;
    for(BigInteger item : value)
    {
        total_value += item;
    }
        //total_value = Decimal value
    vector<BigInteger> new_value;
    while (total_value > 0)
    {
        BigInteger left = (total_value % New_Base);
        new_value.push_back(left);
        total_value = (total_value - left) / New_Base;
    }
    reverse(new_value.begin(), new_value.end());
    string return_value = "";
    for(BigInteger values : new_value)
    {
        return_value += Char_List[values.toInt()];
    }
    return_value = return_value.erase(return_value.find_last_not_of('0')+1);
    Data = return_value;
    return;
}
bool OCSS::check()
{
    string x = "ASC";
    string z = x;
    ToBase(x, 95, 23);
    ToBase(x, 23, 95);
    if (x == z)
    {
        return true;
    }
    return false;
}
