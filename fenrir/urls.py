
from django.conf.urls import patterns, include, url

from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'fenrir.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^$', 'udc.views.index', name='home'),
    url(r'^configure/', 'udc.views.configure', name='home'),
    url(r'^sensors/', 'udc.views.sensors', name='sensors'),
    url(r'^udc/', 'udc.views.cmd', name='cmd'),
    url(r'^retval/', 'udc.views.retval', name='cmd'),
    url(r'^addsys/', 'udc.views.addsys', name='addsys'),
    url(r'^addrule/', 'udc.views.addrule', name='addrule'),
    url(r'^admin/', include(admin.site.urls)),

    #AUTHENTICATION URLS
    (r'^accounts/', include('accounts.urls')),  
)
