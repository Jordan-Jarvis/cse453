#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std; 



/**********************************************************************
* Gets test queries
***********************************************************************/
std::vector<std::string> getTestQueries()
{
  std::vector<std::string> data;
  data.push_back("hello");
    // Generate 12 test cases to represent valid input.
    // Have a function to call all the test cases.

  return data;
}

/**********************************************************************
* Authenticates a user in "SQL" and returns true or false
***********************************************************************/
bool checkAuthentication()
{
    //Query Generation: Accept two strings, return a single string to check if the user is authenticated. 
    return false;
}

/**********************************************************************
* Get test strings for various functions
* Type 1 returns tautology attacks
* Type 2 returns Union Query attacks
* Type 3 returns Comment attacks
* Type 4 returns Additional statement attacks
***********************************************************************/
std::vector<std::string> getTestVulnerabilities(int attackType)
{
  std::vector<std::string> data;
  switch (attackType)
  {
    case 1: //tautology attacks, pattern goes, username, then pass, then username etc..
    {
       data.push_back("Joe"); //username
       data.push_back("anything' or '1' = '1'"); //pass
       
    }
    case 2: // union query
    {
       data.push_back("jam' UNION SELECT ‘a’,NULL,NULL,NULL --"); 
    }
    case 3:
    {
       data.push_back("jam';"); // comment attack
       data.push_back("jam\";"); // comment attack
       
    }
    case 4:
    {
       data.push_back("; rm -R ./"); //additional statement attack
       data.push_back(" && rm -R ./"); //additional statement attack
    }
  }
    // Vulnerabilities: Generate test cases for tautology, 
    // union query, comment and additional statement attacks.

  return data;
}

/**********************************************************************
* Runs weak mitigation on the value passed in and returns it.
***********************************************************************/
string weakMitigation(string Value)
{
    //Weak Mitigation against UNION Query Attack
    const string MATCH = "UNION";
    std::size_t found = Value.find(MATCH);
    if (found!=std::string::npos){
        //Delete substring after found
        Value.erase(Value.find(MATCH), Value.length());
        return Value;
    } else {
        return "String doesn't contain a UNION statement";
    }
    
}

/**********************************************************************
* Ensures complete sanitization of the string then returns it.
***********************************************************************/
string strongMitigation(string Value)
{
    Value = weakMitigation(Value);
    vector<string> array;
    stringstream ss(Value);
    string tmp;
    string sqlArray [] = {
            "ADD","ALTER","ALL","AND","ANY","AS","ASC","BACKUP DATABASE","BETWEEN","CASE","CHECK",
            "COLUMN","CONSTRAINT","CREATE","DATABASE","DEFAULT","DELETE","DESC","DISTINCT","DROP","EXEC",
            "EXISTS","FOREIGN KEY","FROM","FULL OUTER JOIN","GROUP BY","HAVING","IN","INDEX","INNER JOIN",
            "INSERT INTO","IS NULL","IS NOT NULL","JOIN","LEFT JOIN","LIKE","LIMIT","NOT","NOT NULL","OR",
            "ORDER BY","OUTER JOIN","PRIMARY","PROCEDURE","RIGHT JOIN","ROWNUM","SELECT","SET","TABLE",
            "TOP","TRUNCATE TABLE","UNION","UNION ALL","UNIQUE","UPDATE","VALUES","VIEW","WHERE"
    };
    while(std::getline(ss, tmp, ' '))
    {
        array.push_back(tmp);
    }
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < 58; j++) { //58 is the size of sqlArray. sqlArray.size does not work for string arrays.
            if (array[i] == sqlArray[j]) {
                for (int k = i; k < array.size(); k++) {
                    array[k] = array[k + 1];
                }
            }
        }
    }
    string newVal = "";
    for (int i = 0; i < array.size(); i++) {
        newVal = newVal + array[i];
    }
    Value = newVal;
    // Strong Mitigation: create a function which calls 
    // weak mitigation and adds to it until it is 
    // considered strong mitigation.
    return Value;
}

/**********************************************************************
* Runs a series of tests for security sanitization and mitigation.
***********************************************************************/
int main()
{
    
   //Stuff goes here
   return 0;
}
