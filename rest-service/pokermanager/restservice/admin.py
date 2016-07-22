from django.contrib import admin
from .models import RoundModel, TournamentStructureModel, PlayerModel, BuyinStructureModel

admin.site.register(RoundModel)
admin.site.register(TournamentStructureModel)
admin.site.register(PlayerModel)
admin.site.register(BuyinStructureModel)