#!/usr/bin/python
import logging
import datetime
import time
import os
import re
import sys
import MySQLdb
import iptools

#sys.path.append('../../')
#from lib.getalert import *

def getalerts_snort():
   db = MySQLdb.connect(host="localhost", # your host, usually localhost
                        user="root", # your username
                         passwd="password", # your password
                         db="snort") # name of the data base
   
   
   cur = db.cursor() 
   
   #Instantiate Alert Variables
   event = [[]]
   signature = [[]]
   iphdr = [[]]
   sensor = "FoxDen"
   
   
   
   i = 0
   cur.execute("select event.*, iphdr.*, signature.*, tcphdr.*, data.*, sig_class.sig_class_name from event left join iphdr on iphdr.cid=event.cid join signature on signature.sig_id=event.signature left join tcphdr on tcphdr.cid=event.cid left join data on data.cid=event.cid left join sig_class on signature.sig_class_id=sig_class.sig_class_id;")
   for row in cur.fetchall() :
      if i != 0:
         event.append([])
      event[i].append(row[1]) #CID - Event ID
      event[i].append(row[2]) #SIG_ID
      event[i].append(row[19]) #SIG_NAME
      event[i].append(row[40]) #SIG_CLASS
      event[i].append(iptools.ipv4.long2ip(row[6])) #SRC
      event[i].append(iptools.ipv4.long2ip(row[7])) #DST
      event[i].append(row[3].strftime('%Y-%m-%d %H:%M:%S')) #TIME
      event[i].append(row[16]) #IP_PROTO
      event[i].append(row[27]) #TCP SPORT
      event[i].append(row[28]) #TCP DPORT
      event[i].append(row[21]) #SEVERITY
      event[i].append(row[39]) #PAYLOAD
      #print event[i]
      i = i + 1
      
      
   
   

   
   
   
   '''
   #Get Signature List
   i = 0
   cur.execute("SELECT * from signature")
   for row in cur.fetchall() :
      if i != 0:
         signature.append([])
      signature[i].append(row[0]) #SIG_ID
      signature[i].append(row[1]) #SIG_NAME
      i = i + 1

   #Get IPhdr List
   i = 0
   cur.execute("SELECT * from iphdr")
   for row in cur.fetchall() :
      if i != 0:
         iphdr.append([])
      iphdr[i].append(iptools.ipv4.long2ip(row[2])) #SRC
      iphdr[i].append(iptools.ipv4.long2ip(row[3])) #DST
      i = i + 1
   
   #Get & Compile Event List
   i = 0
   cur.execute("SELECT * from event")
   for row in cur.fetchall():
      if i != 0:
         event.append([])
      event[i].append(row[1]) #SID
      event[i].append(row[2]) #SIG_ID
      
      #Match SIG_ID to SIG_NAME
      for j in range (len(signature)):
         if signature[j][0] == event[i][1]:
            event[i].append(signature[j][1]) #SIG_NAME
            
      #Append IPhdr
      try:
         event[i].append(iphdr[i][0]) #SRC
         event[i].append(iphdr[i][1]) #DST
      except:
         pass
      
      event[i].append(row[3].strftime('%Y-%m-%d %H:%M:%S')) #TIME
      i = i + 1
'''
   
   #Purge DBase
   cur.execute("DELETE FROM event")
   cur.execute("DELETE FROM sensor")
   cur.execute("DELETE FROM iphdr")
   cur.execute("DELETE FROM tcphdr")
   cur.execute("DELETE FROM udphdr")
   cur.execute("DELETE FROM icmphdr")
   cur.execute("DELETE FROM data")
   cur.execute("DELETE FROM opt")
   cur.execute("DELETE FROM signature")
   cur.execute("DELETE FROM sig_class")
   cur.execute("DELETE FROM sig_reference")
   cur.execute("DELETE FROM reference")
   cur.execute("DELETE FROM reference_system")
   db.commit()


   return event


   
