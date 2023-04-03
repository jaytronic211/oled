Connect-MicrosoftTeams

$FilePath = ".\output.csv"

$UsersLineURI = Get-CsOnlineUser -Filter {LineURI -ne $Null}

if($UsersLineURI -ne $null)
{
    Write-Host "Processing User Numbers"
    foreach($item in $UsersLineURI)
    {                  
        $Matches = @()
        $Item.LineURI -match $Regex1 | out-null
            
        $myObject1 = New-Object System.Object
        $myObject1 | Add-Member -type NoteProperty -name "LineURI" -Value $Item.LineURI
        $myObject1 | Add-Member -type NoteProperty -name "DDI" -Value $Matches[1]
        $myObject1 | Add-Member -type NoteProperty -name "Ext" -Value $Matches[2]
        $myObject1 | Add-Member -type NoteProperty -name "DisplayName" -Value $Item.DisplayName
        $myObject1 | Add-Member -type NoteProperty -name "FirstName" -Value $Item.FirstName
        $myObject1 | Add-Member -type NoteProperty -name "LastName" -Value $Item.LastName
        $myObject1 | Add-Member -type NoteProperty -name "Type" -Value "User"
        $Array1 += $myObject1          
    }
}

$Array1 | export-csv $FilePath -NoTypeInformation