from django.shortcuts import render

from rest_framework import viewsets
from .models import RoundModel
from .serializers import RoundSerializer

class RoundViewSet(viewsets.ModelViewSet):
    queryset = RoundModel.objects.all()
    serializer_class = RoundSerializer
