from rest_framework import serializers
from .models import RoundModel, TournamentStructureModel, PlayerModel, BuyinStructureModel


class RoundSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = RoundModel
        fields = ('small_blind', 'big_blind', 'round_duration')


class TournamentStructureSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TournamentStructureModel
        fields = ('name', 'rounds')

class PlayerSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = PlayerModel
        fields = ("nick", "rebuy_count", "buyin_structure")

class BuyinStructureSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = BuyinStructureModel
        fields = ("bankroll", "cash")
