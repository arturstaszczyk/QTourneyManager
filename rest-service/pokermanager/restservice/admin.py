from django.contrib import admin
from .models import RoundModel, TournamentStructureModel, ParticipantModel, BuyinStructureModel

admin.site.register(RoundModel)
admin.site.register(TournamentStructureModel)
admin.site.register(ParticipantModel)
admin.site.register(BuyinStructureModel)