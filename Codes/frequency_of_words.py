string maxFrequency(vector<string> str)
{

  map<string,int> m;
  for(int i=0;i<str.size();i++)
    {
        m[str[i]]++;
    }
  int ma=INT_MIN;
  string s="";
  for(auto &val:m)
  {
    if(val.second>ma)
    {

      ma=val.second;
      s=val.first;
    }
      
    
    
    
  }
  
  return s;
  
  
  
  
}
