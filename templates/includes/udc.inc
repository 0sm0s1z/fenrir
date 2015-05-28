<script>
document.getElementById("term_cont").innerHTML += '<div style="width: 100%;">{% if retval %}{% for object in retval %}{{ object }}<br>{% endfor %}{% endif %}</div>';
</script>




