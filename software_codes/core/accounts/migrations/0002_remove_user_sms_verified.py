# Generated by Django 5.0.6 on 2024-05-22 06:36

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('accounts', '0001_initial'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='user',
            name='sms_verified',
        ),
    ]
