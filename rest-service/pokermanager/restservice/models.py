from django.db import models

class RoundModel (models.Model):

    small_blind = models.IntegerField()
    big_blind = models.IntegerField()
    round_duration = models.IntegerField()

    def __str__(self):
        return "Small blind: {}GC - Big blind: {}GC".format(self.small_blind, self.big_blind)

class TournamentStructureModel(models.Model):

    name = models.CharField(max_length=128, unique=True)
    rounds = models.ManyToManyField(RoundModel)

    def __str__(self):
        return self.name

class BuyinStructureModel(models.Model):
    bankroll = models.IntegerField(default=1000)
    cash = models.IntegerField(default=5)

    def __str__(self):
        return "{}GC for {}zl".format(self.bankroll, self.cash)

class ParticipantModel(models.Model):

    nick = models.CharField(max_length=128, unique=True)
    rebuy_count = models.IntegerField(default=1)
    buyin_structure = models.ForeignKey(BuyinStructureModel, on_delete=models.CASCADE, blank=True, null=True)

    def __str__(self):
        return self.nick