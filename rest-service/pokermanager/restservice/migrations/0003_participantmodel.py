# -*- coding: utf-8 -*-
# Generated by Django 1.9 on 2016-07-22 14:59
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('restservice', '0002_auto_20160622_1523'),
    ]

    operations = [
        migrations.CreateModel(
            name='ParticipantModel',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('nick', models.CharField(max_length=128, unique=True)),
                ('initial_stake', models.IntegerField(default=1)),
                ('rebuy_count', models.IntegerField(default=1)),
            ],
        ),
    ]
