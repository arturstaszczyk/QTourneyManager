from rest_framework import serializers
from .models import *


class RoundSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = RoundModel
        fields = ('pk', 'small_blind', 'big_blind', 'round_duration', 'is_break')


class TournamentStructureSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TournamentStructureModel
        fields = ('pk', 'name', 'rounds')

class PlayerSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = PlayerModel
        fields = ('pk', "nick", "rebuy_count", "buyin_structure", "eliminated")

class BuyinStructureSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = BuyinStructureModel
        fields = ('pk', "bankroll", "cash")
