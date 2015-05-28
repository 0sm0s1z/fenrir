import MySQLdb

#DB Connect Globals
db_host = "localhost"
db_user = "root"
db_pass = "password"
db_name = "fenrir"

db = MySQLdb.connect(host=db_host, # your host, usually localhost
                     user=db_user, # your username
                      passwd=db_pass, # your password
                      db=db_name) # name of the data base

def get_profile(type, host):
   cur = db.cursor() 
   
   cur.execute("SELECT * FROM AUTH_PROFILES WHERE host = '" + host + "'")
   
   return cur.fetchall()