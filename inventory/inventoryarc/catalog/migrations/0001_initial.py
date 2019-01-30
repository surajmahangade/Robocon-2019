# Generated by Django 2.1.5 on 2019-01-26 14:59

from django.db import migrations, models
import django.db.models.deletion
import uuid


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Item',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('title', models.CharField(max_length=200)),
                ('summary', models.TextField(help_text='Enter a brief description of the item', max_length=1000)),
            ],
        ),
        migrations.CreateModel(
            name='ItemInstance',
            fields=[
                ('id', models.UUIDField(default=uuid.uuid4, help_text='Unique ID for this particular item across whole inventory', primary_key=True, serialize=False)),
                ('due_back', models.DateField(blank=True, null=True)),
                ('status', models.CharField(blank=True, choices=[('m', 'Maintenance'), ('o', 'On loan'), ('a', 'Available'), ('r', 'Reserved')], default='m', help_text='Item availability', max_length=1)),
                ('item', models.ForeignKey(null=True, on_delete=django.db.models.deletion.SET_NULL, to='catalog.Item')),
            ],
            options={
                'ordering': ['due_back'],
            },
        ),
        migrations.CreateModel(
            name='Itemtype',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(help_text='Enter an item type (e.g. Electronics or mechanical)', max_length=200)),
            ],
        ),
        migrations.CreateModel(
            name='Manufacturer',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('company_name', models.CharField(max_length=100)),
                ('address', models.CharField(max_length=100)),
            ],
            options={
                'ordering': ['company_name', 'address'],
            },
        ),
        migrations.AddField(
            model_name='item',
            name='itemtype',
            field=models.ManyToManyField(help_text='Select an item type for this item', to='catalog.Itemtype'),
        ),
        migrations.AddField(
            model_name='item',
            name='manufacturer',
            field=models.ForeignKey(null=True, on_delete=django.db.models.deletion.SET_NULL, to='catalog.Manufacturer'),
        ),
    ]
