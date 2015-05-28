import socket
import datetime


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
from django.db import IntegrityError, DatabaseError
from django.utils.encoding import DjangoUnicodeDecodeError
from django.test import TestCase, TransactionTestCase
from udc.models import *

# A UDP server

# Set up a UDP server
UDPSock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

# Listen on port 21567
# (to all IP addresses on this system)
listen_addr = ("",2222)
UDPSock.bind(listen_addr)

# Report on all data packets received and
# where they came from in each case (as this is
# UDP, each may be from a different source and it's
# up to the server to sort this out!)
while True:
        raw,addr = UDPSock.recvfrom(1024)
        
        #format details delimit by commas
        data = raw + "," + str(addr[0]) + "," + str(addr[1]) + "," + str(datetime.datetime.utcnow())
        details = data.split(',') 
        
        #Check if agent entry exists else create       
        obj, created = agent_details.objects.get_or_create(
                alias = details[0],
                defaults={
                        'last_check'    : details[4],
                        'status'        : details[1]
                }
                )
        
        #If exists update details
        if created == False:
           update = agent_details.objects.get(alias = details[0])
           update.last_check = details[4]
           update.status = details[1]
           update.save()
        #log = agent_details(alias = details[0], last_check = details[4], status = details[1])
        #log.save()
