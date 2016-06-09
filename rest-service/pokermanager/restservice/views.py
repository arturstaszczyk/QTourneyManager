from django.shortcuts import render

from rest_framework import viewsets
from .models import RoundModel, TournamentStructureModel
from .serializers import RoundSerializer, TournamentStructureSerializer

class RoundViewSet(viewsets.ModelViewSet):
    queryset = RoundModel.objects.all()
    serializer_class = RoundSerializer

class TournamentStructureViewSet(viewsets.ModelViewSet):
    queryset = TournamentStructureModel.objects.all()
    serializer_class = TournamentStructureSerializer
