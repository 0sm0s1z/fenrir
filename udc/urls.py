from django.conf.urls import patterns, url

from udc import views

urlpatterns = patterns('',
    url(r'^$', views.index, name='index')
)
