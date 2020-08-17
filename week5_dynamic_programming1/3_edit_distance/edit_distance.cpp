#include <iostream>
#include <string>

using std::string;
int edit_distance(const string &str1, const string &str2,int m,int n) {
  string temp1,temp2;
  int edit[m+1][n+1];
  for(int i=0;i<=m;i++)
  {
    edit[i][0]=i;
  }
  for(int j=0;j<=n;j++)
  {
    edit[0][j]=j;
  }

  if(m==0)
  {
    return n;
  }
  if(n==0)
  {
    return m;
  }
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(str1[i-1]==str2[j-1])
      {
        edit[i][j]=edit[i-1][j-1];
      }
      else
      {
        int x=1+edit[i][j-1];
        int y=1+edit[i-1][j];
        int z=1+edit[i-1][j-1];
        edit[i][j]=std::min(std::min(x,y),z);
      }
      
    }
  }
  return edit[m][n];
  /*if (str1==str2)
  {
    return 0;
  }
  if(str1[m-1]==str2[n-1])
  {
    return edit_distance(str1,str2,m-1,n-1);
  }
  else
  {
    return 1+min(edit_distance(str1,str2,m,n-1),edit_distance(str1,str2,m-1,n),edit_distance(str1,str2,m-1,n-1));
  }*/
  
  /*for(int i=0;i<m;i++)
  {
    temp1=str1[i];
    for(int j=0;j<n;j++)
    {
      temp2=str2[j];
      if(temp1==temp2)
      {
        count++;
      }
    }
  }
  return count;*/
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2,str1.length(),str2.length()) << std::endl;
  return 0;
}
