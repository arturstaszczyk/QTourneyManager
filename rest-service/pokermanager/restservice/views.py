from rest_framework import viewsets
from .serializers import *
from .forms import PasswordForm
from .models import AdminModel
from django.http import JsonResponse
import base64
from django.views.decorators.csrf import csrf_exempt


from django.shortcuts import render

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

def save_new_password(password):
    admin_model = AdminModel.objects.get(pk=1)
    if admin_model == None:
        admin_model = AdminModel()

    admin_model.device_id = None

    hash = sha3.sha3_256()
    hash.update(password.encode())
    encoded = hash.digest()

    encoded = base64.b64encode(encoded)

    admin_model.password = encoded

    admin_model.save()

@csrf_exempt
def login_view(request):
    if request.method == 'POST':

        print(request.POST['password'])
        #print(request.POST['device_id'])

        if('device_id' not in request.POST):
            save_new_password(request.POST['password'])
        else:
            admin_model = AdminModel.objects.get(pk=1)
            if admin_model == None:
                admin_model = AdminModel()

            allow = False
            print(admin_model.password)
            if(admin_model.password == request.POST['password']):
                admin_model.device_id = request.POST['device_id']
                admin_model.save()
                allow = True
            else:
                admin_model.device_id = ""

            return JsonResponse({'allow': True}) if allow else JsonResponse({'allow': False})

    form = PasswordForm()

    return render(request, 'pages/login.html', {'form': form})