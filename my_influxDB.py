from influxdb import InfluxDBClient as influxdb

def setInfluxDB(detect):
    data = [{
            'measurement' : 'revolvingDoor',
            'tags' : {
                    'VisionUni' : '123'
            },
            'fields' : {
                    'detect' : detect
            }
    }]

    try:
        client = influxdb('localhost', 8086, 'root', 'root', 'revolvingDoorDB')
    except Exception as e:
        print("Exception : " + str(e))

    if client is not None:
        try:
            client.write_points(data)
        except Exception as e:
            print("Exception write : " + str(e))
        finally:
            client.close()
    print(f"running influxdb OK : {detect}")
