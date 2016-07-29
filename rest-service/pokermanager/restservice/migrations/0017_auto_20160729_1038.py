# -*- coding: utf-8 -*-
# Generated by Django 1.9 on 2016-07-29 10:38
from __future__ import unicode_literals

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('restservice', '0016_auto_20160729_1005'),
    ]

    operations = [
        migrations.AlterField(
            model_name='roundmodel',
            name='tournament',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='rounds', to='restservice.TournamentStructureModel'),
        ),
    ]
