#include <stdio.h>
#include <sqlite3.h> 

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {

   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   //const char* data = "Callback function called";
   const char* data = "";

////////////// Ouverture de la base de données //////////////  

   rc = sqlite3_open("LaSainteDB.db", &db);

   if( rc ) {
      fprintf(stderr, "[ERREUR] - Impossible d'ouvrir la base de données : %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "[INFO] - Base de données ouverte avec succès\n\n");
   }
   
////////////// Extraction des données //////////////
  
   /* Creation de la requête */
   sql = "SELECT * from utilisateur;";

   /* Execution de la requête SQL */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "[ERROR] - SQL : %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "\n[INFO] - Fin des données.\n\n");
   };
   sqlite3_close(db);
   return 0;
  
}
