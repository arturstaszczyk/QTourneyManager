from django.contrib import admin
from .models import *

admin.site.register(RoundModel)
admin.site.register(TournamentStructureModel)
admin.site.register(PlayerModel)
admin.site.register(BuyinStructureModel)

admin.site.register(AdminModel)