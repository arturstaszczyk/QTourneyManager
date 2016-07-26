from django.shortcuts import get_object_or_404
from rest_framework import viewsets
from rest_framework.response import Response
from .serializers import *

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