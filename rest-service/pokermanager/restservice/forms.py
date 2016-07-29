from django import forms
from .models import AdminModel

class PasswordForm(forms.ModelForm):
    class Meta:
        model = AdminModel
        fields = ('password',)