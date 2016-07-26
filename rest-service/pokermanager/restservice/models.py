from django.db import models

class RoundModel (models.Model):

    is_break = models.BooleanField(default=False)
    small_blind = models.IntegerField()
    big_blind = models.IntegerField()
    round_duration = models.IntegerField()

    def __str__(self):
        return "Break {} sec".format(self.round_duration) if self.is_break else\
            "{} GC/{} GC - {} sec".format(self.small_blind, self.big_blind, self.round_duration)

class TournamentStructureModel(models.Model):

    name = models.CharField(max_length=128, unique=True)
    round_list = models.ManyToManyField(RoundModel, through="RoundOrderModel")

    def __str__(self):
        return self.name

class RoundOrderModel(models.Model):
    number = models.PositiveIntegerField()
    round_model = models.ForeignKey(RoundModel)
    structure = models.ForeignKey(TournamentStructureModel)

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