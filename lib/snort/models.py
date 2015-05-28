from django.db import models

class signature(models.Model):
   sig_id = models.IntegerField(max_length=10)
   sig_name = models.CharField(max_length=200)
   sig_class_id = models.IntegerField(max_length=10)
   sig_priority = models.IntegerField(max_length=10)
   sig_rev = models.IntegerField(max_length=10)
   sig_sid = models.IntegerField(max_length=10)
   sid_sid = models.IntegerField(max_length=10)
   
