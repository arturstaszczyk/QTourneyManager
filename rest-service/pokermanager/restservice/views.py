from django.shortcuts import render

from rest_framework import viewsets
from .models import RoundModel, TournamentStructureModel, PlayerModel, BuyinStructureModel
from .serializers import RoundSerializer, TournamentStructureSerializer, PlayerSerializer, BuyinStructureSerializer

class RoundViewSet(viewsets.ModelViewSet):
    queryset = RoundModel.objects.all()
    serializer_class = RoundSerializer

class TournamentStructureViewSet(viewsets.ModelViewSet):
    queryset = TournamentStructureModel.objects.all()
    serializer_class = TournamentStructureSerializer

class PlayersViewSet(viewsets.ModelViewSet):
    queryset = PlayerModel.objects.all()
    serializer_class = PlayerSerializer

class BuyinStructureViewSet(viewsets.ModelViewSet):
    queryset = BuyinStructureModel.objects.all()
    serializer_class = BuyinStructureSerializer