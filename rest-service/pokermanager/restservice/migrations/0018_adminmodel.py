# -*- coding: utf-8 -*-
# Generated by Django 1.9 on 2016-07-29 14:04
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('restservice', '0017_auto_20160729_1038'),
    ]

    operations = [
        migrations.CreateModel(
            name='AdminModel',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('device_id', models.UUIDField()),
                ('password', models.CharField(max_length=128)),
            ],
        ),
    ]
