#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>


int zbxHttpPost(char *uri, char *response);
int zbxGetAuthToken(char *zbxUri, char *zbxUser, char *zbxPass, char *zbxAuthId);



int main(void)
{
  json_t *json = json_object();

  int zbxVersion = json_object_set(json, "jsonrpc", json_string("2.0"));
  if (zbxVersion != 0)
    return -1;
  
  int zbxMethod = json_object_set(json, "method", json_string("user.login"));
  if (zbxMethod != 0)
    return -1;   

  json_t *uidParams = json_pack("{s:s, s:s}", "user", "jreed", "password", "Flight8152LA");
  int zbxParams = json_object_set(json, "params", uidParams);
  if (zbxParams != 0)
    return -1; 

  int zbxId = json_object_set(json, "id", json_integer((json_int_t)1));
  if (zbxId != 0)
    return -1;
  
  size_t jsonFLAGS = JSON_INDENT(4) | JSON_PRESERVE_ORDER ;
  puts(json_dumps(json,jsonFLAGS));
  
  return 0;
}
