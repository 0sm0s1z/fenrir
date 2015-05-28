import sys
sys.path.append('../')

#Database
'''
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
'''



#Signature Libraries
from snort.get_sigs import *

snortalerts = getalerts_snort()

'''
i = 0
for alert in snortalerts:
   log = alerts(severity = alert[10], sensor = "FoxDen", sensor_eid = alert[0], sensor_sid = alert[1], source = alert[4], destination = alert[5], signature = alert[2], signature_class = alert[3], time = alert[6], protocol = alert[7], sport = str(alert[8]), dport = str(alert[9]), payload = str(alert[11]))
   log.save()
   i = i + 1
'''

def syncalerts():
    from snort.get_sigs import getalerts_snort
    from udc.models import alerts
    snortalerts = getalerts_snort()
    i = 0
    for alert in snortalerts:
        try:
           log = alerts(severity = alert[10], sensor = "FoxDen", sensor_eid = alert[0], sensor_sid = alert[1], source = alert[4], destination = alert[5], signature = alert[2], signature_class = alert[3], time = alert[6], protocol = alert[7], sport = str(alert[8]), dport = str(alert[9]), payload = str(alert[11]))
           log.save()
           i = i + 1
        except:
            break

    