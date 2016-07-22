# -*- coding: utf-8 -*-
# Generated by Django 1.9 on 2016-07-22 15:09
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('restservice', '0003_participantmodel'),
    ]

    operations = [
        migrations.CreateModel(
            name='BuyinStructureModel',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('bankroll', models.IntegerField(default=1000)),
                ('cash', models.IntegerField(default=5)),
            ],
        ),
        migrations.RemoveField(
            model_name='participantmodel',
            name='initial_stake',
        ),
    ]
