from django.db import models
import sha3


class TournamentStructureModel(models.Model):

    name = models.CharField(max_length=128, unique=True)

    def __str__(self):
        return self.name

class RoundModel (models.Model):

    is_break = models.BooleanField(default=False)
    small_blind = models.IntegerField()
    big_blind = models.IntegerField()
    round_duration = models.IntegerField()
    number = models.PositiveIntegerField()
    tournament = models.ForeignKey(TournamentStructureModel, related_name='rounds')

    def __str__(self):
        breakStr = str(self.tournament.name) + " [{}. BREAK] {} sec".format(self.number, self.round_duration)
        roundStr = str(self.tournament.name) + " [{}. ROUND] {} GC/{} GC - {} sec".format(self.number, self.small_blind,
                                                                                          self.big_blind, self.round_duration)
        return breakStr if self.is_break else roundStr


class BuyinStructureModel(models.Model):

    bankroll = models.IntegerField(default=1000)
    cash = models.IntegerField(default=5)

    def __str__(self):
        return "{}GC for {}zl".format(self.bankroll, self.cash)

class PlayerModel(models.Model):

    nick = models.CharField(max_length=128, unique=True)
    rebuy_count = models.IntegerField(default=1)
    eliminated = models.BooleanField(default=False)
    buyin_structure = models.ForeignKey(BuyinStructureModel, on_delete=models.CASCADE, blank=True, null=True)

    def __str__(self):
        return self.nick

class AdminModel(models.Model):

    device_id = models.UUIDField(null=True)
    password = models.CharField(max_length=128)

    def __str__(self):
        return self.password