#!/usr/bin/python
import sys
import os

#Fenrir Imports
from lib.ssh_connect import *
from lib.dictionary import *
#from auth.db_connect import *


##Database Connection
'''
from django.conf import settings
settings.configure(
DATABASES = {
    'default' : {
        'ENGINE': 'django.db.backends.sqlite3',
        'NAME': "db.sqlite3",
        'USER': '',
        'PASSWORD': '',
        'HOST': '',
    }
}
)
from django.db import models
from udc.models import *
'''

def exec_cmd(sshAuth, cmd):
    #Make the Command Universal
    #cmd = formatcmd(sshAuth["system"], cmd)
    print "wtf"
    
    #Execute the command
    #os.system("python lib/ssh_connect.py")
    
       


def get_hostid(var):
    print var
    profile = auth_profiles.objects.get(id=1)
    print profile.id
    return profile.id
