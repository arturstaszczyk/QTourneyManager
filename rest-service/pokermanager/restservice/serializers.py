from rest_framework import serializers
from .models import RoundModel, TournamentStructureModel


class RoundSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = RoundModel
        fields = ('small_blind', 'big_blind', 'round_duration')


class TournamentStructureSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TournamentStructureModel
        fields = ('name', 'rounds')