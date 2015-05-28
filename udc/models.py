from django.db import models

class auth_profiles(models.Model):
   system = models.CharField(max_length=200)
   version = models.CharField(max_length=200)
   alias = models.CharField(max_length=200)
   host = models.CharField(max_length=200)
   username = models.CharField(max_length=200)
   password = models.CharField(max_length=200)
   authkey = models.CharField(max_length=200)
   
class alerts(models.Model):
   severity = models.CharField(max_length=200)
   sensor = models.CharField(max_length=200)
   sensor_eid = models.CharField(max_length=200)
   sensor_sid = models.CharField(max_length=200)
   source = models.CharField(max_length=200)
   destination = models.CharField(max_length=200)
   signature = models.CharField(max_length=200)
   signature_class = models.CharField(max_length=200)
   time = models.CharField(max_length=200)
   protocol = models.CharField(max_length=200)
   sport = models.CharField(max_length=200)
   dport = models.CharField(max_length=200)
   payload = models.CharField(max_length=200)

class rules(models.Model):
   alias = models.CharField(max_length=200)
   sensor = models.CharField(max_length=200)
   zone = models.CharField(max_length=200)
   source = models.CharField(max_length=200)
   destination = models.CharField(max_length=200)
   protocol = models.CharField(max_length=200)
   service = models.CharField(max_length=200)
   
class agent_details(models.Model):
   alias = models.CharField(max_length=200)
   last_check = models.CharField(max_length=200)
   status = models.CharField(max_length=200)