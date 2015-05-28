#The purpose of this file is to grab and parse sensor data for the purpose of syncronization with the Fenrir Database
import sys
sys.path.append("../")
from ssh_connect import ssh_exec
from django.conf import settings
settings.configure(
DATABASES = {
    'default' : {
        'ENGINE': 'django.db.backends.sqlite3',
        'NAME': "/home/osm0s1z/fenrir/db.sqlite3",
        'USER': '',
        'PASSWORD': '',
        'HOST': '',
    }
}
)
from django.db import models
from udc.models import *




def sync_iptables(sensorid):
   cmd = "iptables -vnL --line-numbers"

   profile = auth_profiles.objects.get(id=sensorid)

   sshAuth = {
   "system"   : profile.system,
   "host"     : profile.host,
   "user"     : profile.username,
   "pass"     : profile.password,
   "key"      : "/home/osm0s1z/fenrir/auth/ssh/id_rsa"
   }
   alias = profile.alias
   sensor = "iptables"
   zone = "external"
   

   #ssh to target sensor & execute command
   rawdata = ssh_exec(sshAuth, cmd)

   rulenum = []
   target = []
   proto = []
   inface = []
   outface = []
   source = []
   dest = []
   content = []
   
   #parse line by line   
   for line in rawdata:
      i = 0
      rule = 0
      for item in line.split(' '):
         if item != "" and item.isdigit() and i == 0:
            rulenum.append(item)
            rule = 1
         elif item != "" and rule == 1 and i == 3:
            target.append(item)
         elif item != "" and rule == 1  and i == 4:
            proto.append(item)
         elif item != "" and rule == 1  and i == 6:
            inface.append(item)
         elif item != "" and rule == 1  and i == 7:
            outface.append(item)
         elif item != "" and rule == 1  and i == 8:
            source.append(item)
         elif item != "" and rule == 1  and i == 9:
            dest.append(item)
         elif item != "" and rule == 1  and i >= 10:
            content.append(item)
         if item != "":
            i = i +1

   i = 0 #RULE COUNTER
   j = 0 #TOTAL RULES
   k = [] #CHAIN BLOCKS
   l = 1 #BLOCK COUNTER
   for rule in rules.objects.all():
      if int(rulenum[j]) == 1:
        k.append(j)
      j = j + 1
   k.append(j)
   try:
    j = k[l]      
    for tuple in rulenum:
       print rulenum[i], target[i], proto[i], inface[i], outface[i], source[i], dest[i], (' ').join(content).split('\n')[i]
       port = (' ').join(content).split('\n')[i].split(':')[1].split(' ')[0]
       print int(rulenum[i])
       if int(rulenum[i]) == 1:
          print "wtf"
          print l
          print k[l]
          l = l + 1
          try:
             j = k[l]
          except:
             pass
         
       print j
          
       if int(rulenum[i]) > j:
          log = rules(alias = alias, sensor = sensor, zone = zone, source = source[i], destination = dest[i], protocol = proto[i], service = port)
          log.save()
          print "New Rule Added!"
       i = i + 1

   except:
       print "Adding first rule for system: " + profile.alias
       port = (' ').join(content).split('\n')[i].split(':')[1].split(' ')[0]
       log = rules(alias = alias, sensor = sensor, zone = zone, source = source[i], destination = dest[i], protocol = proto[i], service = port)
       log.save()

def sync_cisco():
   print "Cisco!"
   
   
   
#Get system/sensor

#system = sys.argv[1]
#sensor = sys.argv[2]
sensor = "iptables"
sensorid = 1

def_sensor = {
	"iptables" : sync_iptables,
	"cisco"    : sync_cisco
}

def_sensor[sensor](sensorid)