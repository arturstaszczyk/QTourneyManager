from django.db import models

class RoundModel (models.Model):

    small_blind = models.IntegerField()
    big_blind = models.IntegerField()
    round_duration = models.IntegerField()

    def __str__(self):
        return str.format("Small blind: %d - Big blind: %d", self.small_blind, self.big_blind)

class TournamentStructureModel(models.Model):

    name = models.CharField(max_length=128, unique=True)
    rounds = models.ManyToManyField(RoundModel)

    def __str__(self):
        return self.name
